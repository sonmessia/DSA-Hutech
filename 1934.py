class SubstringCounter:
    def __init__(self, s):
        self.s = s
        self.n = len(s)
        self.base = 31  # Số nguyên tố nhỏ
        self.mod = 10**9 + 7  # Số nguyên tố lớn để tránh tràn số
        self.hash_prefix = [0] * (self.n + 1)
        self.powers = [1] * (self.n + 1)

        # Tính hash prefix và power trước để tăng tốc truy vấn
        for i in range(1, self.n + 1):
            self.powers[i] = (self.powers[i - 1] * self.base) % self.mod
            self.hash_prefix[i] = (self.hash_prefix[i - 1] * self.base + ord(s[i - 1]) - ord('a') + 1) % self.mod

    def get_hash(self, l, r):
        """Lấy hash của s[l:r] (chỉ số 0-based)"""
        h = (self.hash_prefix[r + 1] - self.hash_prefix[l] * self.powers[r - l + 1]) % self.mod
        return h if h >= 0 else h + self.mod

    def count_occurrences(self, m, l, r):
        """Đếm số lần xuất hiện của chuỗi m trong đoạn [l, r]"""
        k = len(m)
        if k > (r - l + 1):
            return 0  # Nếu m dài hơn đoạn con thì không thể xuất hiện

        m_hash = 0
        for c in m:
            m_hash = (m_hash * self.base + ord(c) - ord('a') + 1) % self.mod

        count = 0
        for i in range(l, r - k + 2):
            if self.get_hash(i, i + k - 1) == m_hash:
                count += 1
        return count


# Đọc đầu vào và thực hiện truy vấn
s = input().strip()
q = int(input())

counter = SubstringCounter(s)

for _ in range(q):
    l, r, m = input().split()
    l, r = int(l) - 1, int(r) - 1  # Chuyển về 0-based index
    print(counter.count_occurrences(m, l, r))
