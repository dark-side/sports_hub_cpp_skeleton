FROM fedora:39

RUN dnf install -y gcc-c++ make cmake poco-devel postgresql-devel openssl-devel && dnf clean all

WORKDIR /app

COPY . .

RUN if [ ! -d "/app/external" ]; then dnf install -y git && dnf clean all; fi
RUN if [ ! -d "/app/external" ]; then git clone https://github.com/Thalhammer/jwt-cpp.git /app/external/jwt-cpp; fi

RUN cmake -DJWT_CPP_INCLUDE_DIR=/app/external/jwt-cpp/include . && cmake --build . --target auth_service

EXPOSE 8080

CMD ["./auth_service"]
