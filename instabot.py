import instaloader
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from time import sleep
from InstagramAPI import InstagramAPI



list = []
following_users = []

L = instaloader.Instaloader()
# L.login(username, password)

post = instaloader.Post.from_shortcode(L.context, shortcode)

post_likes = post.get_likes()
print(post_likes)

for likee in post_likes:
    list.append(likee.username)

print(list)


api = InstagramAPI(uid, passforuid)
api.login()


def follow_users(users_list):
    api.login()
    api.getSelfUsersFollowing()  # Get users which you are following
    result = api.LastJson
    for user in result['users']:
        following_users.append(user['pk'])
    for user in users_list:
        if not user['pk'] in following_users:  # if new user is not in your following users
            print('Following @' + user['username'])
            api.follow(user['pk'])
            # after first test set this really long to avoid from suspension
            sleep(20)
        else:
            print('Already following @' + user['username'])
            sleep(10)


follow_users(list)
