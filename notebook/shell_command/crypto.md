# crypto
Symmetric v.s. Asymmetric Key Cryptosystem
Symmetric Cryptosystem – Block Cipher Mode of Operation
Asymmetric Cryptosystem – RSA
(Asymmetric Cryptosystem – ECC)

對稱式加密系統像是傳統鎖頭，非對稱加密系統像是喇叭鎖


## AES
### ECB(Electronic Codebook)

#### encrypted

            plainText
                |
key -> [block ciper encryption]
                |
            cipher text

#### decrypted

           cipher text
                |
key -> [block ciper encryption]
                |
            PlainText

'same block has same result'

### CBC

#### encrypted

            plainText
                |
 IV ---------> xor
                |
key -> [block ciper encryption]
                |
                |
            cipher text ------------> next IV

#### encrypted

            Cipher text
                |
                --------------------------> next IV
                |
key -> [block ciper encryption]
                |
                |
  IV    ------->|
                |
             plaintetx


block offset , block offset , don't padding

### CTR

#### encrypted
                 00000000 -> 00000001
        {Nonce , Counter} <=> IV
                |
                |
key -> [block ciper encryption]
                |
                |
plaintext ---- xor
                |
            cipher text


#### decrypted
                 00000000  -> 00000001
        {Nonce , Counter} <=> IV
                |
                |
key -> [block ciper encryption]
                |
                |
Cipher    ---- xor
                |
            Plain text

```info
Block Cipher Mode of Operation
Propagating Cipher Block Chaining (PCBC)
Cipher Feedback (CFB)
Output Feedback (OFB)
https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation
````

## RSA
Fermat theorem
RSA problem
rsa


## ECC
galois field
ecc addation
http://crypto.nknu.edu.tw/textbook/chap6.pdf
https://zh.wikipedia.org/wiki/%E6%A4%AD%E5%9C%86%E6%9B%B2%E7%BA%BF

P + Q + R = 0
P + Q + Q = 0
P + Q + 0 = 0
P + P + 0 = 0


# test
1.which aes need IV ?

2. 3^456134842334 mod 5 = ?
=> because 3^4 mod 5 = 1
=>(3^4)^114033710583 *  3^2 mod 5 
=> 1 * 3^2 mod 5 = 4


Ans: 4

