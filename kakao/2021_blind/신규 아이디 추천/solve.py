import re


def solution(new_id):
    text = new_id
    text = text.lower()
    text = re.sub("[^a-z0-9-_.]", "", text)
    text = re.sub("\.{2,}", ".", text)
    text = re.sub("^[.]|[.]$", "", text)
    text = "a" if len(text) == 0 else text[:15]
    if text[-1] == ".":
        text = text[:-1]
    text = (
        text
        if len(text) > 2
        else text + "".join([text[-1] for i in range(3 - len(text))])
    )
    return text
