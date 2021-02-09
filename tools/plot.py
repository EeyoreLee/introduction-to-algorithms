# -*- encoding: utf-8 -*-
'''
@create_time: 2021/02/09 16:48:16
@author: lichunyu
'''

def func2(image_path):
    import matplotlib.pyplot as plt
    from PIL import Image
    top_left_x, top_left_y, width, height = 0, 0, 0, 0
    image = Image.open(image_path).convert('RGB')
    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)
    rect = plt.Rectangle((top_left_x, top_left_y), width, height, fill=False, edgecolor = 'red',linewidth=1)
    ax.add_patch(rect)
    plt.imshow(image) # 图像数组
    plt.show()


def func1():
    from PIL import ImageDraw
    from PIL import Image
    path = ''
    image = Image.open(path) # 打开一张图片
    draw = ImageDraw.Draw(image) # 在上面画画
    draw.rectangle([645,465,200,200], outline=(255,0,0)) # [左上角x，左上角y，右下角x，右下角y]，outline边框颜色
    image.show() 


def func3():
    import cv2
    image_path = ''
    image = cv2.imread(image_path)
    first_point = (100, 100)
    last_point = (1000, 1000)
    image1= cv2.rectangle(image, first_point, last_point, (0, 255, 0), 2)
    cv2.imwrite('image.jpg', image1)
    cv2.imshow('image.jpg', image1)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()
