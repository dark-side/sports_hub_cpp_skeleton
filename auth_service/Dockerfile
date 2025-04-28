FROM fedora:39

RUN dnf install -y gcc-c++ make cmake poco-devel postgresql-devel openssl-devel && dnf clean all

WORKDIR /app

COPY . .

RUN cmake . && cmake --build . --target auth_service

EXPOSE 8080

CMD ["./auth_service"]
