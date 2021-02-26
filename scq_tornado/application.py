#!/usr/bin/env Python
# coding=utf-8
from url import url
import tornado.web
import os

settings = dict(
    template_path=os.path.join(os.path.dirname(__file__), "templates"),
    static_path=os.path.join(os.path.dirname(__file__), "statics"),
    cookie_secret='0Q1AKOKTQHqaa+N80XhYW7KCGskOUE2snCW06UIxXgI=',
    xsrf_cookies=False,
    autoreload=True,
    #static_url_prefix='/statics/',
    # 'login_url': '/login',
    debug=True,
    log_path=os.path.join(os.path.dirname(__file__), 'logs/log')
)

application = tornado.web.Application(
    handlers=url,
    **settings
)
