import pytesseract
from PIL import Image
text = pytesseract.image_to_string(Image.open('n.png'), lang='chi_sim')

print(text)
print(dir(pytesseract.pytesseract))
