# -*- encoding: utf-8 -*-
'''
@create_time: 2020/06/16 15:03:48
@author: lichunyu
'''


import json
import math
import os
import io
import requests
import time
import datetime
import hashlib
import codecs
import uuid
import traceback


def testapi(appkey, appsecret):
    # appkey = "APPKEY"  #这里输入提供的app_key
    # appsecret = "APPSECRET"  #这里输入提供的app_secret

    api_url = "http://fapiao.glority.cn/v1/item/get_item_info"
    image_url = "http://fapiao.glority.cn/dist/img/sample.jpg"
    result = {}
    try:
        # generate timestamp
        timestamp = int(time.time())

        # generate token
        m = hashlib.md5()
        token = appkey + "+" + str(timestamp) + "+" + appsecret
        m.update(token.encode('utf-8'))
        token = m.hexdigest()

        # post request
        data = {
            'image_url': image_url,
            'app_key': appkey,
            'timestamp': str(timestamp),
            'token': token
        }
        r = requests.post(api_url, data=data)
        if r.status_code != 200:
            print("failed to get info from : ", image_url)
        else:
            result = r.json()
            print(result)
    except:
        traceback.print_exc()
    return result


if __name__ == '__main__':
    appkey = '5ed70435'
    appsecret = '92576291692f1fc31ba60d0c215ca630'
    testapi(appkey, appsecret)
