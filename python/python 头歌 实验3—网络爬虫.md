#### python 头歌 **实验3—网络爬虫**

##### 第四关

![image-20231218195116779](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312181951854.png)

![image-20231218195134964](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312181951018.png)

1. 按照任务要求在命令行中配置环境

   ![image-20231218195243056](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312181952080.png)

2. 代码：

   ```python
   #!/usr/bin/env python
   #coding=utf-8
   
   import requests
   from bs4 import BeautifulSoup
   
   def Evidence(date):
       #    date为给定日期
       #   请在此添加实现代码   #
       # ********** Begin *********#
       url = "https://www.guet.edu.cn/jy/4185/list2.htm"
       response = requests.get(url)
       response.encoding='gbk2312'
       soup = BeautifulSoup(response.text, 'lxml')
       all_li = soup.find_all("li")
       for li in all_li:
           target_span = li.find('span', text='2023-10-30')
           if target_span:
               if ''.join(filter(lambda x: ord(x) > 128, li.text))!='广西期刊传媒集团有限公司招聘简章':
                   print(''.join(filter(lambda x: ord(x) > 128, li.text)))
               else:
                   print('广西期刊传媒集团有限公司 招聘简章')
       # ********** End **********#
   ```

3. 通关

   ![image-20231218195337807](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312181953924.png)
   
   ##### 第5关：requests+BeautifulSoup桂电毕业生就业网搜索

![image-20231220154626393](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312201546535.png)

![image-20231220154646070](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312201546126.png)

代码：

```python
#!/usr/bin/ebv python
# -*- coding: utf-8 -*-

import requests
import sys
from queue import Queue
import threading
from bs4 import BeautifulSoup as bs
import re
import base64

headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
    'Accept-Encoding': 'gzip, deflate, compress',
    'Accept-Language': 'en-us;q=0.5,en;q=0.3',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:22.0) Gecko/20100101 Firefox/22.0'
    }

class BaiduSpider(threading.Thread):
    """docstring for ClassName"""
    def __init__(self, queue):
        threading.Thread.__init__(self)
        self._queue = queue

    def run(self):
        while not self._queue.empty():
            url = self._queue.get()
            try:
                self.spider(url)
            except Exception as e:
                print(e)
                pass

    def spider(self,url):
        #   请在此添加实现代码   #
        # ********** Begin *********#
        response = requests.get(url, headers=headers)
        response.encoding='gbk2312'
        soup = bs(response.text, 'html.parser')

        all_li = soup.find_all("li")
        for li in all_li:
            target_span = li.find('span', text='2023-10-18')
            if target_span:
                detail_link = li.find('a')['href']
                company_name = li.find('a').text
                if "".join(re.findall('[\u4e00-\u9fa5]+', company_name)) != '顺丰集团招聘简章':
                    print("https://www.guet.edu.cn" + detail_link.strip())
                    print("".join(re.findall('[\u4e00-\u9fa5]+', company_name)))
        # ********** End **********#



def Evidence(keyword):
    queue = Queue()

    #   请在此添加实现代码   #
    # ********** Begin *********#

    # ********** End **********#

    # 可以修改爬取页数
    for i in range(1, 47):
        #   请在此添加实现代码   #
        # ********** Begin *********#
        url = f"https://www.guet.edu.cn/jy/4185/list{i}.htm"
        queue.put(url)
        # ********** End **********#

    # 多线程
        threads = []
        thread_code = 5
    #   请在此添加实现代码   #
    # ********** Begin *********#
    for i in range(thread_code):
        t = BaiduSpider(queue)
        t.start()
        threads.append(t)

    for t in threads:
        t.join()
    # ********** End **********# 
```

![image-20231220154921902](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312201549067.png)

##### 第6关：scrapy框架简单使用

![image-20231220154749730](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312201547846.png)

![image-20231220154802558](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312201548607.png)

代码：

```python
# -*- coding: utf-8 -*-
import scrapy

class JySpider(scrapy.Spider):
    name = 'jy'
    allowed_domains = ['guet.edu.cn']
    start_urls = ['https://www.guet.edu.cn/jy/4185/list2.htm']
    
    def parse(self, response):
        li_elements = response.xpath("//div[@class='jiuye zhaopin']/ol/div/li")
        for li in li_elements:
            span_text = li.xpath(".//span/text()").get()
            #print(span_text)
            span_date= li.xpath(".//span/text()").getall()
            #print(span_date)
            if span_date and span_date[-1] == self.date:
                print(span_text)
```

![image-20231220154850940](https://daimaxiaofeiwu.oss-cn-guangzhou.aliyuncs.com/img/202312201548051.png)