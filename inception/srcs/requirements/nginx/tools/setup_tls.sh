#!/bin/sh
set -e

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -newkey rsa:4096 \
  -keyout /etc/nginx/ssl/selfsigned.key \
  -out /etc/nginx/ssl/selfsigned.crt \
  -days 365 \
  -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=student/CN=${DOMAIN_NAME}"

echo "Self-signed TLS certificate generated for ${DOMAIN_NAME}"
