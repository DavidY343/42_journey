FROM alpine:3.19

RUN apk update && apk add --no-cache php82 php82-fpm php82-mysqli php82-curl php82-gd php82-mbstring php82-opcache php82-json php82-session php82-zlib php82-dom php82-exif wget netcat-openbsd

RUN mkdir -p /var/www/html && wget https://wordpress.org/latest.tar.gz && tar -xzf latest.tar.gz -C /var/www/html --strip-components=1 && rm latest.tar.gz

COPY tools/ /setup/

EXPOSE 9000

ENTRYPOINT ["sh", "/setup/entrypoint.sh"]
