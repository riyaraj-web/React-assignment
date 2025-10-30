import re

def is_valid_email(email: str) -> bool:
    pattern = re.compile(
        r"^[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+"
        r"(?:\.[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+)*@"
        r"(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?\.)+"
        r"[A-Za-z]{2,}$"
    )
    return bool(pattern.fullmatch(email.strip()))

email = "Enter your Email here ..."

if is_valid_email(email):
    print("✅ Valid email address")
else:
    print("❌ Invalid email address")
