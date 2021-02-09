# -*- encoding: utf-8 -*-
'''
@create_time: 2021/02/09 14:50:22
@author: lichunyu
'''

import torch
import torchvision
from PIL import Image
import torchvision.transforms as trns
from PIL import ImageDraw
# image = Image.open(path) # 打开一张图片



transform = trns.ToTensor()
image_path = '/Users/lichunyu/Downloads/DSC01643.JPG'
image = Image.open(image_path).convert("RGB")
image_tensor = transform(image)
print(image_tensor.size())


model = torchvision.models.detection.fasterrcnn_resnet50_fpn(pretrained=True, )
# print(model)
model.eval()
x = [torch.rand(3, 300, 400), torch.rand(3, 500, 400)]
predictions = model([image_tensor])
draw = ImageDraw.Draw(image) # 在上面画画
for i in predictions:
    for coor, label in zip(i['boxes'], i['labels']):
        if label.item() == 1:
            draw.rectangle([coor[0].item(),coor[1].item(),coor[2].item(),coor[3].item()], outline=(0,255,0)) # [左上角x，左上角y，右下角x，右下角y]，outline边框颜色
image.show() 
pass