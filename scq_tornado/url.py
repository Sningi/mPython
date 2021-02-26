#!/usr/bin/env Python
# coding=utf-8
"""
the url structure of website
"""

from handlers.html import HtmlHandler, ErrorHandler, IndexHandler
from handlers.resource import ResourceHandler, FileHandler

url = [
    (r"/", IndexHandler),
    (r"/index.html", IndexHandler),
    (r"/html/.*?.html", HtmlHandler),
    (r"/images/.*?", ResourceHandler),
    #(r"/css/.*?", ResourceHandler),
    (r"/case/.*?", ResourceHandler),
    (r"/js/.*?", ResourceHandler),
    (r"/sourse/.*?", ResourceHandler),
    (r"/file", FileHandler),
    #(r".*?", ErrorHandler)
]
