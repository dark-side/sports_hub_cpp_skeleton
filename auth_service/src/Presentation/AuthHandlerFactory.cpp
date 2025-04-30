#include "AuthHandlerFactory.h"
#include "UsersHandler.h"
#include "SignInHandler.h"
#include "SignOutHandler.h"
#include "OptionsHandler.h"
#include <regex>

using namespace Poco::Net;
using namespace std;

namespace {
    bool urlContains(const std::string& url, const std::string& pattern) {
        regex r(pattern);
        auto url_begin = sregex_iterator(url.begin(), url.end(), r);
        auto url_end = sregex_iterator();

        return std::distance(url_begin, url_end) == 1;
    }
}


HTTPRequestHandler* AuthHandlerFactory::createRequestHandler(const HTTPServerRequest& request) {
    const auto& url = request.getURI();

    cout << "URL: " << url << endl;

    const auto& method = request.getMethod();

    cout << "Method: " << method << endl;

    if (urlContains(url, "/auth/sign_in") && method == "OPTIONS") {
        return new OptionsHandler();
    }

    if (urlContains(url, "/users") && method == "POST") {
        return new UsersHandler();
    }

    if (urlContains(url, "/auth/sign_in") && method == "POST") {
        return new SignInHandler();
    }

    if (urlContains(url, "/auth/sign_out") && method == "DELETE") {
        return new SignOutHandler();
    }

    throw Poco::NotFoundException("Unknown request method");
}
