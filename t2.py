
def q_6():
    def q_6_1(string):
        result = ""
        for char in string:
            # 字符串中遍历所有的字符
            if char.isdigit():
                # 如果这个字符是数字
                result += char
                # 将这个字符取出来加到结果中
        print("6.1 result:\t", result)

    def q_6_2(string):
        char_dict = dict()
        for char in string:
            # 字符串中遍历所有的字符
            if char.isalpha():
                # 如果这个字符是字母
                char = char.lower()
                # 忽略大小写，统一转换为小写
                if char in char_dict:
                    # 如果这个字母已经在字典中，计数加1
                    char_dict[char] += 1
                else:
                    # 如果这个字母还没有加到字典中，就新加进去,计数为1
                    char_dict[char] = 1
        print("6.2 result:\t", char_dict)

    def q_6_3(string):
        result = ""
        for char in string:
            # 字符串中遍历所有的字符
            if char.isalpha():
                # 如果这个字符是字母
                char = char.lower()
                # 忽略大小写，统一转换为小写，注释：忽略大小写存在第一次出现为大写的情况，需求不明确，暂定为按小写处理
            if char not in result:
                result += char
        print("6.3 result:\t", result)

    a = "aAsmr3idd4bgs7Dlsf9eAF"

    q_6_1(a)
    q_6_2(a)
    q_6_3(a)


def q_7():
    def get_strip(b_list):
        # 去除列表的奇数位
        result = []
        for index, item in enumerate(b_list):
            # 带索引（第几位）的遍历列表
            if (index+1) % 2 == 0:
                #注意，第一个瓶子的索引是0
                #取模，如果是偶数位，保留
                result.append(item)
        return result

    b_100 = [i for i in range(1,101)]
    # 1-100的数字列表生成式
    while len(b_100) > 1:
        #取出
        b_100 = get_strip(b_100)
        # print(b_100) #可以打印每轮剩下的瓶子号
    print("7. result:\t", b_100)


if __name__ == '__main__':
    q_6()
    q_7()
