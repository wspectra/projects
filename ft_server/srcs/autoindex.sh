if grep -q "autoindex off" /etc/nginx/sites-available/nginx.conf
then sed -i 's/autoindex off/autoindex on/g' /etc/nginx/sites-available/nginx.conf && echo "autoindex on."
else sed -i 's/autoindex on/autoindex off/g' /etc/nginx/sites-available/nginx.conf && echo "autoindex off."
fi
service nginx restart
