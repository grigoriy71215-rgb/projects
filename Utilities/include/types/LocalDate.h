#pragma once

#include <chrono>
#include <memory>

class __attribute__((visibility("default"))) LocalDate {
private:
  class Impl;
  std::unique_ptr<Impl> pimpl;

public:
  LocalDate();
  explicit LocalDate(const std::chrono::local_seconds &time);
  LocalDate(int year, int month, int day);
  ~LocalDate();

  LocalDate(const LocalDate &other);
  LocalDate(LocalDate &&other) noexcept;
  LocalDate &operator=(const LocalDate &other);
  LocalDate &operator=(LocalDate &&other) noexcept;

  static LocalDate now();
  static LocalDate from_string(const char *str,
                               const char *format = "%Y-%m-%d");

  int year() const;
  int month() const;
  int day() const;
  const std::chrono::local_seconds &get_time() const;

  LocalDate &add_days(int days);
  LocalDate &add_months(int months);
  LocalDate &add_years(int years);

  bool operator==(const LocalDate &other) const;
  bool operator!=(const LocalDate &other) const;
  bool operator<(const LocalDate &other) const;
  bool operator>(const LocalDate &other) const;
  bool operator<=(const LocalDate &other) const;
  bool operator>=(const LocalDate &other) const;

  int days_between(const LocalDate &other) const;
  bool is_leap_year() const;
  int day_of_week() const;

  char *to_cstring(const char *format = "%Y-%m-%d") const;
  void free_cstring(char *str) const;

  class InputWithFormat;
  class StringProxy;

  InputWithFormat with_format(const char *format) const;
};

class LocalDateInputHelper;
std::ostream &operator<<(std::ostream &os, const LocalDate &date);
std::istream &operator>>(std::istream &is, LocalDate &date);
std::istream &operator>>(std::istream &is, const LocalDateInputHelper &helper);

class LocalDateInputHelper {
private:
  const char *format_;
  LocalDate &date_;

public:
  LocalDateInputHelper(const char *format, LocalDate &date);
  friend std::istream &operator>>(std::istream &is,
                                  const LocalDateInputHelper &helper);
};

class LocalDate::StringProxy {
private:
  class Impl;
  std::unique_ptr<Impl> pimpl;

public:
  StringProxy(const char *str);
  ~StringProxy();
  StringProxy(const StringProxy &other);
  StringProxy(StringProxy &&other) noexcept;
  StringProxy &operator=(const StringProxy &other);
  StringProxy &operator=(StringProxy &&other) noexcept;

  const char *c_str() const;
  operator const char *() const;
};

class LocalDate::InputWithFormat {
private:
  const char *format_;
  const LocalDate &date_;

public:
  InputWithFormat(const char *format, const LocalDate &date);
  LocalDateInputHelper operator>>(LocalDate &target) const;
};
