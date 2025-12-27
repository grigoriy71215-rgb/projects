#include "types/LocalDate.h"
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class LocalDate::Impl {
public:
  std::chrono::local_seconds time;

  Impl() : time(std::chrono::local_seconds::min()) {}
  Impl(const std::chrono::local_seconds &t) : time(t) {}
  Impl(int year, int month, int day) {
    std::chrono::year_month_day ymd{
        std::chrono::year{year},
        std::chrono::month{static_cast<unsigned>(month)},
        std::chrono::day{static_cast<unsigned>(day)}};
    time = std::chrono::local_seconds{
        std::chrono::sys_days{ymd}.time_since_epoch()};
  }
};

class LocalDate::StringProxy::Impl {
public:
  std::string str;

  Impl(const char *s) : str(s ? s : "") {}
};

LocalDate::LocalDate() : pimpl(std::make_unique<Impl>()) {}
LocalDate::LocalDate(const std::chrono::local_seconds &time)
    : pimpl(std::make_unique<Impl>(time)) {}
LocalDate::LocalDate(int year, int month, int day)
    : pimpl(std::make_unique<Impl>(year, month, day)) {}
LocalDate::~LocalDate() = default;
LocalDate::LocalDate(const LocalDate &other)
    : pimpl(std::make_unique<Impl>(*other.pimpl)) {}
LocalDate::LocalDate(LocalDate &&other) noexcept = default;
LocalDate &LocalDate::operator=(const LocalDate &other) {
  if (this != &other)
    pimpl = std::make_unique<Impl>(*other.pimpl);
  return *this;
}
LocalDate &LocalDate::operator=(LocalDate &&other) noexcept = default;

LocalDate LocalDate::now() {
  auto now = std::chrono::system_clock::now();
  auto days = std::chrono::floor<std::chrono::days>(now);
  return LocalDate{std::chrono::local_seconds{days.time_since_epoch()}};
}

LocalDate LocalDate::from_string(const char *str, const char *format) {
  if (!str || !format) {
    throw std::invalid_argument("Null pointer in from_string");
  }
  std::tm tm = {};
  std::stringstream ss(str);
  ss >> std::get_time(&tm, format);
  if (ss.fail()) {
    throw std::invalid_argument("Invalid date string or format");
  }
  auto time_t = std::mktime(&tm);
  auto sys_time = std::chrono::system_clock::from_time_t(time_t);
  auto days = std::chrono::floor<std::chrono::days>(sys_time);
  return LocalDate{std::chrono::local_seconds{days.time_since_epoch()}};
}

int LocalDate::year() const {
  auto ymd = std::chrono::year_month_day{
      std::chrono::floor<std::chrono::days>(pimpl->time)};
  return static_cast<int>(ymd.year());
}

int LocalDate::month() const {
  auto ymd = std::chrono::year_month_day{
      std::chrono::floor<std::chrono::days>(pimpl->time)};
  return static_cast<unsigned>(ymd.month());
}

int LocalDate::day() const {
  auto ymd = std::chrono::year_month_day{
      std::chrono::floor<std::chrono::days>(pimpl->time)};
  return static_cast<unsigned>(ymd.day());
}

const std::chrono::local_seconds &LocalDate::get_time() const {
  return pimpl->time;
}

LocalDate &LocalDate::add_days(int days) {
  pimpl->time += std::chrono::days{days};
  return *this;
}

LocalDate &LocalDate::add_months(int months) {
  auto ymd = std::chrono::year_month_day{
      std::chrono::floor<std::chrono::days>(pimpl->time)};
  ymd += std::chrono::months{months};
  pimpl->time =
      std::chrono::local_seconds{std::chrono::sys_days{ymd}.time_since_epoch()};
  return *this;
}

LocalDate &LocalDate::add_years(int years) {
  auto ymd = std::chrono::year_month_day{
      std::chrono::floor<std::chrono::days>(pimpl->time)};
  ymd += std::chrono::years{years};
  pimpl->time =
      std::chrono::local_seconds{std::chrono::sys_days{ymd}.time_since_epoch()};
  return *this;
}

bool LocalDate::operator==(const LocalDate &other) const {
  return pimpl->time == other.pimpl->time;
}

bool LocalDate::operator!=(const LocalDate &other) const {
  return pimpl->time != other.pimpl->time;
}

bool LocalDate::operator<(const LocalDate &other) const {
  return pimpl->time < other.pimpl->time;
}

bool LocalDate::operator>(const LocalDate &other) const {
  return pimpl->time > other.pimpl->time;
}

bool LocalDate::operator<=(const LocalDate &other) const {
  return pimpl->time <= other.pimpl->time;
}

bool LocalDate::operator>=(const LocalDate &other) const {
  return pimpl->time >= other.pimpl->time;
}

int LocalDate::days_between(const LocalDate &other) const {
  auto diff = std::chrono::floor<std::chrono::days>(pimpl->time) -
              std::chrono::floor<std::chrono::days>(other.pimpl->time);
  return diff.count();
}

bool LocalDate::is_leap_year() const {
  return std::chrono::year{year()}.is_leap();
}

int LocalDate::day_of_week() const {
  auto sys_days = std::chrono::floor<std::chrono::days>(pimpl->time);
  std::chrono::weekday wd{sys_days};
  return wd.c_encoding();
}

char *LocalDate::to_cstring(const char *format) const {
  auto sys_time = std::chrono::sys_time<std::chrono::seconds>{
      pimpl->time.time_since_epoch()};
  auto time_t = std::chrono::system_clock::to_time_t(sys_time);
  std::tm tm = *std::localtime(&time_t);
  std::stringstream ss;
  ss << std::put_time(&tm, format);
  std::string result = ss.str();
  char *cstr = new char[result.size() + 1];
  std::strcpy(cstr, result.c_str());
  return cstr;
}

void LocalDate::free_cstring(char *str) const { delete[] str; }

LocalDate::StringProxy::StringProxy(const char *str)
    : pimpl(std::make_unique<Impl>(str)) {}
LocalDate::StringProxy::~StringProxy() = default;
LocalDate::StringProxy::StringProxy(const StringProxy &other)
    : pimpl(std::make_unique<Impl>(*other.pimpl)) {}
LocalDate::StringProxy::StringProxy(StringProxy &&other) noexcept = default;
LocalDate::StringProxy &
LocalDate::StringProxy::operator=(const StringProxy &other) {
  if (this != &other)
    pimpl = std::make_unique<Impl>(*other.pimpl);
  return *this;
}

LocalDate::StringProxy &
LocalDate::StringProxy::operator=(StringProxy &&other) noexcept = default;

const char *LocalDate::StringProxy::c_str() const { return pimpl->str.c_str(); }
LocalDate::StringProxy::operator const char *() const {
  return pimpl->str.c_str();
}

LocalDate::InputWithFormat LocalDate::with_format(const char *format) const {
  return InputWithFormat(format, *this);
}

LocalDate::InputWithFormat::InputWithFormat(const char *format,
                                            const LocalDate &date)
    : format_(format), date_(date) {}

LocalDateInputHelper
LocalDate::InputWithFormat::operator>>(LocalDate &target) const {
  return LocalDateInputHelper(format_, target);
}

LocalDateInputHelper::LocalDateInputHelper(const char *format, LocalDate &date)
    : format_(format), date_(date) {}

std::ostream &operator<<(std::ostream &os, const LocalDate &date) {
  char *cstr = date.to_cstring();
  os << cstr;
  date.free_cstring(cstr);
  return os;
}

std::istream &operator>>(std::istream &is, LocalDate &date) {
  std::string str;
  is >> str;
  try {
    date = LocalDate::from_string(str.c_str());
  } catch (const std::exception &e) {
    is.setstate(std::ios::failbit);
  }
  return is;
}

std::istream &operator>>(std::istream &is, const LocalDateInputHelper &helper) {
  std::string str;
  is >> str;
  try {
    helper.date_ = LocalDate::from_string(str.c_str(), helper.format_);
  } catch (const std::exception &e) {
    is.setstate(std::ios::failbit);
  }
  return is;
}
