#ifndef AUTHSERVICEAPP_H
#define AUTHSERVICEAPP_H

#include <Poco/Util/ServerApplication.h>

class AuthServiceApp : public Poco::Util::ServerApplication {
protected:
    int main(const std::vector<std::string>&) override;
};


#endif //AUTHSERVICEAPP_H
