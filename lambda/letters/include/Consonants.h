#pragma onse

#include <string>
#include <vector>

class Consonants {
private:
  std::vector<std::string> voicedConsonants = {
      "б, в, г, д, ж, з, й, л, м, н, р, ц"};
  std::vector<std::string> pairedConsonantsh = {"б, в, г, ж, з"};
  std::vector<std::string> voicelessConsonants = {
      "к, п, с, т, ф, х, ц, ч, ш, щ"};
  bool getConsonants() const noexcept;
};
