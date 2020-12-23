from selenium import webdriver

chrome_options = webdriver.ChromeOptions()
# chrome_options.add_argument('--headless')
chrome_options.add_argument('--disable-gpu')
browser = webdriver.Chrome(executable_path="chromedriver.exe", options=chrome_options)
result = browser.get("http://www.baidu.com")
print(result.status)
