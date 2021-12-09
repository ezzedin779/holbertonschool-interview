#!/usr/bin/python3
"""how many ho ?"""
from requests import get


RED = "https://www.reddit.com/"
HEAD = {'user-agent': 'my-app/0.0.1'}


def count_words(subreddit, word_list, prev="", _dict={}):
    """RECUSIVE + API"""
    if not _dict:
        for word in word_list:
            _dict[word] = 0
    if prev is None:
        word_list = [[key, value] for key, value in _dict.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for w in word_list:
            if w[1]:
                print("{}: {}".format(w[0].lower(), w[1]))
        return None
    url = RED + "r/{}/hot/.json".format(subreddit)
    param = {'limit': 100, 'after': prev}
    r = get(url, headers=HEAD, params=param, allow_redirects=False)
    if r.status_code != 200:
        return None
    try:
        js = r.json()
    except ValueError:
        return None
    try:
        info = js.get("data")
        prev = info.get("after")
        ch = info.get("children")
        for child in ch:
            info2 = child.get("data")
            title = info2.get("title")
            lower = [i.lower() for i in title.split(' ')]
            for w in word_list:
                _dict[w] += lower.count(w.lower())
    except Exception:
        return None

    count_words(subreddit, word_list, prev, _dict)
