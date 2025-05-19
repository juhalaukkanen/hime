# What's this?

About 10 years ago I extracted the password validation method from SNES
game Ganbare Goemon: Yukihime Kyūshutsu Emaki (がんばれゴエモン〜ゆき姫救出絵巻〜).

https://goemon.fandom.com/wiki/The_Legend_of_the_Mystical_Ninja

I translated the 65c816 assembly to C(++) by the help of emulator debugger.
I made test cases and just aimed that the translated code produces the same
result as the original.
The code looks horrible. I ended the _curiosity quest_ before I polished
the code to be actually readable. Thus, it was left in write-only state.

# Why?

Password routines in oldskool games do fascinate me.
Most of the games having password system are already reversed, analysed
and documented very comprehensively.

Bisqwit has excellent resource for password generators and analysis.
Even videos giving insights how exactly things do work! Do check out!

https://github.com/bisqwit/password_codecs

Somehow this game was overlooked. Even the USA version of the game.
The game had possibility for short password (7 or 8 letters) where
mainly the stage number was encoded.
Then also longer ones (32 or 52 letters) which encoded money, items, skills, and such.

## The background: why exactly this game

I remember seeing in the instructions manual screenshot pictures taken on
stuff which were actually impossible. Such as having Kabuki skills in stage one.

Take a look at the pages 11 & 17 of the USA version instruction booklet:

https://www.gamesdatabase.org/Media/SYSTEM/Nintendo_SNES/Manual/formated/The_Legend_of_the_Mystical_Ninja_-_1991_-_Konami.pdf

The people whole wrote the instruction booklet seemed to have taken the fun
to max by using the tool that the author of the password routine provided.
At least I assume this is what happened!

### Food for thought
Actually I would be thrilled to hear this from the developers! Why is no-one producing this kind of oldskool video game development insights?
Interviewing devs about the development tools, methods, algoritms, etc.
Too narrow audience? Hopefully someone is even considering to produce this
kind of documentary.

## The challenge

Anyway, I chose the Japanese version to understand the extra spice that katakana and hiragana added.

# What is included here

+ The password verification routine
+ Several test cases
+ Address and instruction annotations
+ Very rough and kludgy way to print the tested password between the test cases (sorry about that)

# What is definitely missing

+ The password encoding routine
+ Complete analysis what values values are encoded and how
+ Any user input, so the actual tooling part
+ Checksum analysis
+ Bounds and input validation analysis
+ More challenging testing per branching condition

# I don't understand anything what is going on here!
Since now there are AI tools, and don't see very big effort to refactor the
code to be actually readable.
The included test cases should secure that the refactored output still
matches my intermediate ASM-to-C translation.

# Then why don't you do it?
Too little time.

If you have the time and passion, I am very happy to assist to get you up to speed.
