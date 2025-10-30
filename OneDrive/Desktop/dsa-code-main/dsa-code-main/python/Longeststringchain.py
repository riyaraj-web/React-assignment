from typing import List

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=len)
        chain = {}
        for word in words:
            chain[word] = 1
            for i in range(len(word)):
                predecessor = word[:i] + word[i+1:]
                if predecessor in chain:
                    chain[word] = max(chain[word], chain[predecessor] + 1)
        return max(chain.values())


if __name__ == "__main__":
    s = Solution()
    words = ["a", "b", "ba", "bca", "bda", "bdca"]
    print("Input words:", words)
    print("Longest String Chain Length:", s.longestStrChain(words))
