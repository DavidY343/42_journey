FROM alpine:3.21

RUN apk update && apk add --no-cache mariadb mariadb-client

COPY tools/ /docker-entrypoint-initdb.d/

COPY conf/my.cnf /etc/my.cnf

EXPOSE 3306

ENTRYPOINT ["sh", "/docker-entrypoint-initdb.d/init_maria.sh"]
