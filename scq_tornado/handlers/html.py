from tornado.web import RequestHandler


class HtmlHandler(RequestHandler):
    def get(self):
        #print('HtmlHandler:' + self.request.uri)
        try:
            self.render(self.request.uri[1:], title='Sning')
        except FileNotFoundError:
            self.write("No such html")


class IndexHandler(RequestHandler):
    def get(self):
        #print('IndexHandler:' + self.request.uri)
        self.render('index.html')


class ErrorHandler(RequestHandler):
    def get(self):
        #print('ErrorHandler:' + self.request.uri)
        self.write("No such file")
