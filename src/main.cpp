#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/stopwatch.h"


int main(int argc, char *argv[])
{
    std::cout << "argc == " << argc << '\n';
 
    for (int ndx{}; ndx != argc; ++ndx)
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
    std::cout << "argv[" << argc << "] == "
              << static_cast<void*>(argv[argc]) << '\n';
 
 
    spdlog::info("Sample Info output.");
    spdlog::warn("Sample Warn output.");
    spdlog::error("Sample Error output.");

    auto filelog = spdlog::basic_logger_mt("sample-logger", "sample-log.txt");
    filelog->set_level(spdlog::level::trace);
    filelog->set_pattern("[p:%P t:%t][%D %H:%M:%S.%e][%n][%l][%@] %v");
    spdlog::stopwatch sw;    
    filelog.get()->debug("Elapsed {}", sw);
    filelog.get()->info("Sample Info output.");
    filelog.get()->warn("Sample Warn output.");
    filelog.get()->error("Sample Error output.");
    filelog.get()->debug("Elapsed {:.3}", sw);  



    return argc == 3 ? EXIT_SUCCESS : EXIT_FAILURE; // optional return value
}