# Asymeric key
- 1. Diffie–Hellman Key Exchange
- 2. Baby-Step Giant-Step
- 3. Pohlig Hellman Algorithm
    CRT: Chinese Remanider Theorem


# Gets your hand dirty
- EDR Fromate
    type
    length
    value

# openssl
- generate key
openssl genrsa -out private.pem 4096
openssl rsa -in private.pem -pubout > public.pem

- analysis key
openssl rsa -pubin -text -noout < public.pem
openssl rsa -in private.pem -text -noout

- encrypted and decrypted
openssl rsautl -encrypt -pubin -inkey public.pem -in data -out data.enc
openssl rsautl -decrypt -inkey private.pem -in data.enc -out data.after

# python
- dir() can show this class function members
        rather than attribute

```python
>>> from Crypto.PublicKey import RSA
>>> rsa = RSA.importKey(open('public.pem').read())
>>> dir(RSA)
['DerNull', 'DerObject', 'DerSequence', 'RSAImplementation', 'Random', '_RSA', '_RSAobj', '__all__', '__builtins__', '__doc__', '__file__', '__name__', '__package__', '__revision__', '_fastmath', '_impl', '_slowmath', 'algorithmIdentifier', 'b', 'bchr', 'binascii', 'bord', 'bstr', 'bytes_to_long', 'construct', 'error', 'generate', 'getRandomRange', 'importKey', 'inverse', 'long_to_bytes', 'pubkey', 'struct', 'sys', 'tobytes']

```

# Rabin Cryptosystem
# pollard"s p algorithm

