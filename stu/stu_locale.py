import locale
language = locale.getlocale()
encoding = locale.getpreferredencoding()
defaultlocale = locale.getdefaultlocale()
print("language", language)
print("encoding", encoding)
print('defaultlocale', defaultlocale)
