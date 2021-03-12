Citys = ['北京', '天津', '石家庄', '太原', '呼和浩特',
         '沈阳', '大连', '长春', '哈尔滨', '上海', '南京',
         '杭州', '宁波', '合肥', '福州', '厦门', '南昌',
         '济南', '青岛', '郑州', '武汉', '长沙', '广州',
         '深圳', '南宁', '海口', '重庆', '成都', '贵阳',
         '昆明', '西安', '兰州', '西宁', '银川',
         '乌鲁木齐', '唐山', '秦皇岛', '包头', '丹东',
         '锦州', '吉林', '牡丹江', '无锡', '扬州', '徐州',
         '温州', '金华', '蚌埠', '安庆', '泉州', '九江',
         '赣州', '烟台', '济宁', '洛阳', '平顶山', '宜昌',
         '襄阳', '岳阳', '常德', '惠州', '湛江', '韶关',
         '桂林', '北海', '三亚', '泸州', '南充', '遵义', '大理']


def gen_months(date_start, date_end):
    year_s = int(date_start[:4])
    year_e = int(date_end[:4])
    month_s = int(date_start[4:])
    month_e = int(date_end[4:])

    months = []
    for year in range(year_s, year_e+1):
        if year_s == year_e:
            for month in range(month_s, month_e+1):
                months.append((year, month))
        else:
            if year == year_s:
                for month in range(month_s, 13):
                    months.append((year, month))
            elif year == year_e:
                for month in range(1, month_e+1):
                    months.append((year, month))
            else:
                for month in range(1, 13):
                    months.append((year, month))

    return months
