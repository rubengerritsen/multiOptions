#include <boost/program_options.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  
  boost::program_options::options_description desc("Available options");
  desc.add_options()("help,h", "produce help message")(
      "options,p",
      boost::program_options::value<std::vector<std::string>>()
          ->multitoken(),
      "option to change");

  boost::program_options::variables_map vm;
  boost::program_options::store(
      boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count("options")) {
		std::vector<std::string> optionsToChange = vm["options"].as<std::vector<std::string>>();
    for (auto &opt : optionsToChange) {
      std::cout << opt << std::endl;
    }
  }
}
