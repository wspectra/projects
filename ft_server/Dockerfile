FROM	debian:buster

RUN		apt-get update && \
		apt-get  -y upgrade && \
		apt-get -y install wget &&\
		apt-get -y install nginx &&\
		apt-get -y install mariadb-server &&\
		apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring &&\
		apt-get -y install vim -y

COPY	./srcs/nginx.conf /etc/nginx/sites-available/
RUN 	rm -f ./etc/nginx/sites-enabled/default
RUN		ln -s  /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf

WORKDIR	/var/www/html/

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN		tar -xf phpMyAdmin-5.0.1-english.tar.gz
RUN		rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN		mv phpMyAdmin-5.0.1-english phpmyadmin
COPY		./srcs/config.inc.php phpmyadmin


RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz
RUN rm -rf latest.tar.gz
COPY ./srcs/wp-config.php /var/www/html/

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Moscow/L=moscow/O=21/OU=21School/CN=localhost" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt



EXPOSE 80 443


RUN rm index.nginx-debian.html
COPY	./srcs/start.sh ./
COPY	./srcs/autoindex.sh ./
RUN chmod -R 755 /var/www/html/*.sh
CMD bash ./start.sh
