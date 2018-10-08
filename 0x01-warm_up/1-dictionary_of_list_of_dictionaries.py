#!/usr/bin/python3
""" Records all tasks from all employees """
import json
import requests

if __name__ == '__main__':
    base_url = "https://jsonplaceholder.typicode.com/"
    user_req = requests.get("{}{}".format(base_url, "users"))
    users = user_req.json()
    todo_req = requests.get("{}{}".format(base_url, "todos"))
    todos = todo_req.json()

    output = {}
    for i in range(len(users)):
        u = users[i]['id']
        output[u] = []
        username = users[i]['name']
        for j in range(len(todos)):
            todo = todos[j]
            title = todo['title']
            completed = todo['completed']
            task = {'username': username, 'task': title, 'completed': completed}
            output[u].append(task)

    with open("todo_all_employees.json", mode="w") as fd:
        json.dump(output, fd)
