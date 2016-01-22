#coding=utf-8
import urllib
import urllib2
import re
import sys
from HTMLParser import HTMLParser




user_agent = 'Mozilla/5.0 (X11; Linux x86_64)'
url = "http://news.baidu.com"
headers = {'User-Agent':user_agent}

try:
	request =urllib2.Request(url,headers = headers)
	response = urllib2.urlopen(request)
except urllib2.URLError,e:
	if hasattr(e,"code"):
		print e.code
	if hasattr(e,"reason"):
		print e.reason

content = response.read().decode("gbk")

title_pattern = re.compile(r'<title.*?>(.*?)</title>',re.S)
text_pattern = re.compile(r'<(.*?)>(.*?)<.*?>',re.S)
url_pattern = re.compile(r'<a.*?href="(.*?)".*?>.*?</a>',re.S)          

titles = re.findall(title_pattern,content)
texts = re.findall(text_pattern,content)
urls =re.findall(url_pattern,content)

#for title in titles:print title

ignore_label=["script","meta","link","style","object"]

def canIgnore(word):
	for label in ignore_label:
		if label in word:return True
	return False

for text in texts:
	if canIgnore(text[0]):continue
	if text[1].strip():
		#print text[1].replace(" ","").replace("\n","")
		print text[1]

#for url in urls:print url



