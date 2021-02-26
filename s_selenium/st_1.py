from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.common.exceptions import TimeoutException
import time
import unittest

# browser = webdriver.Chrome()
# browser.get("http://sso.jwc.whut.edu.cn/Certification/toIndex.do")
# print(browser.page_source)


def login():
    username = browser.find_element_by_id("username")
    username.send_keys("0121508720110")
    password = browser.find_elements_by_name("password")
    # time.sleep(1)
    password[0].click()
    password[0].send_keys('s96097019mg')


def getGrade():
    time.sleep(1)
    browser.find_elements_by_id("submit_id")[0].click()
    browser.get("http://202.114.50.130/Score")
    browser.find_elements_by_partial_link_text("成绩查询")[1].click()
    time.sleep(1)


def mDriver():
    print("Use Chrome...")
    options = Options()
    # options.add_argument('--headless')
    prefs = {"profile.managed_default_content_settings.images": 3}
    options.add_experimental_option("prefs", prefs)
    # 设置好应用扩展
    extension_path = './ublock.crx'
    options.add_extension(extension_path)
    return webdriver.Chrome(options=options)


class FirefoxDemo(unittest.TestCase):
    def setUp(self):
        # 创建Firefox浏览器的一个Options实例对象
        profile = webdriver.FirefoxProfile()
        # 禁用CSS加载
        profile.set_preference('permissions.default.stylesheet', 2)
        # 禁用images加载
        profile.set_preference('permissions.default.image', 3)
        profile.set_preference("javascript.enabled", False)
        # 禁用flash插件
        # profile.set_preference(
        #     'dom.ipc.plugins.enabled.libflashplayer.so', False)
        # 启动带有自定义设置的Firefox浏览器
        self.driver = webdriver.Firefox(firefox_profile=profile)
        self.driver.install_addon('/home/sning/wallpaper/wallpaper/extensions/uBlock.xpi')

    def test_forbidImageFirefox(self):
        self.driver.get("http://jandan.net/ooxx/page-28#comments")
        time.sleep(10)

    def tearDown(self):
        self.driver.quit()


def main():
    url = "http://jandan.net/ooxx/page-28#comments"
    driver = mDriver()
    driver.set_page_load_timeout(10)
    # 加载插件
    # time.sleep(1)
    try:
        print("get data...")
        driver.get(url)
    except TimeoutException:
        print("timeout")
        driver.execute_script('window.stop()')
    rs = []
    try:
        rs = driver.find_elements_by_class_name('view_img_link')
    except TimeoutException:
        print("get elements timeout")
        body = []
    for i in rs:
        print(i.get_attribute('href'))
    time.sleep(3)


if __name__ == '__main__':
    unittest.main()
