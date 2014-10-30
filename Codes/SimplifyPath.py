class Solution:
# @param path, a string
# @return a string
    def simplifyPath(self, path):
        result = []
        pathList = path.split('/')
        for content in pathList:
            if content and content == '..':
                if len(result) > 0:
                    result.pop()
                else:
                    result = []
            elif content and content != '.':
                result.append(content)
        return '/'+'/'.join(result)