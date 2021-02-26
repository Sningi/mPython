import os
import json
from tornado.web import RequestHandler


class ResourceHandler(RequestHandler):
    def get(self):
        #print('ResourceHandler', self.request.uri)
        try:
            # pic = open('templates' + self.request.uri, 'rb')
            # pics = pic.read()
            self.write(open('templates' + self.request.uri, 'rb').read())
            # self.set_header("Content-type", self.request.uri)
        except FileNotFoundError:
            self.write('No such file')


class FileHandler(RequestHandler):
    def get(self):
        self.render('html/upload.html')

    def post(self):
        ret = {'result': 'OK'}
        file_metas = self.request.files.get(
            'file', None)  # 提取表单中‘name’为‘file’的文件元数据

        if not file_metas:
            ret['result'] = 'Invalid Args'
            return ret

        for meta in file_metas:
            filename = meta['filename']
            file_path = '/home/sning/Downloads/' + filename

            with open(file_path, 'wb') as up:
                up.write(meta['body'])

        self.write(json.dumps(ret))
