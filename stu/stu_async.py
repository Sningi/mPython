# import time
# import asyncio


# async def say_after(delay, what):
#     await asyncio.sleep(delay)
#     print(what)


# async def main():
#     task1 = asyncio.create_task(
#         say_after(1, 'hello'))

#     task2 = asyncio.create_task(
#         say_after(2, 'world'))

#     print(f"started at {time.strftime('%X')}")

#     # Wait until both tasks are completed (should take
#     # around 2 seconds.)
#     await task1
#     await task2

#     print(f"finished at {time.strftime('%X')}")
# asyncio.run(main())


# async def fi():
#     task2 = asyncio.create_task(
#         say_after(4, 'world'))
#     await task2
# asyncio.run(fi())

# print(f"finished at {time.strftime('%X')}")
# import asyncio


# async def nested():
#     return 42


# async def main():
#     # Schedule nested() to run soon concurrently
#     # with "main()".
#     task = asyncio.create_task(nested())

#     # "task" can now be used to cancel "nested()", or
#     # can simply be awaited to wait until it is complete:
#     await task

# asyncio.run(main())
import asyncio


async def nested():
    return 42


async def main():
    # Nothing happens if we just call "nested()".
    # A coroutine object is created but not awaited,
    # so it *won't run at all*.
    await nested()

    # Let's do it differently now and await it:
    print(await nested())  # will print "42".

asyncio.run(main())
