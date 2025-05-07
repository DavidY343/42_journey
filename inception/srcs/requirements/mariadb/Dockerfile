FROM alpine:3.19

RUN apk update && apk add --no-cache mariadb mariadb-client

COPY tools/ /docker-entrypoint-initdb.d/

EXPOSE 3306

ENTRYPOINT ["sh", "/docker-entrypoint-initdb.d/init.sh"]
