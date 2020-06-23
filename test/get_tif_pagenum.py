from PIL import Image
import os

count = 0
# i = 0
tiffs_path = "/Users/lichunyu/Desktop/earlee/test"
filename = os.path.join(tiffs_path, '2.tif')
# for filename in os.listdir(tiffs_path):
#     if filename.endswith(".tif"):

img = Image.open(filename)
for i in range(1, 6):
# while True:
    try:
        img.seek(i)
        img.save('page_%s.tif'%(i,))
        # print(filename)
        # print(count)
    except EOFError:
        break
    # count += 1
# print(count)
pass
