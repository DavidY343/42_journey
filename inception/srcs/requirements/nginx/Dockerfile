FROM alpine:3.19

RUN apk update && apk add --no-cache nginx openssl

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/init_tls.sh /setup/init_tls.sh

RUN sh /setup/init_tls.sh

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
