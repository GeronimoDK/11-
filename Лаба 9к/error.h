#include <exception>
using namespace std;


class error : public exception {
public:
    const char* what() const noexcept override {
        return "An error has occurred.";
    }
};
