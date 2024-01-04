#include "App.h"

int main(int argc, char **argv) {
    try {
        auto app = App(argc, argv);
        app.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}