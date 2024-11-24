vocabulary = 'I am Hamlet the prince of Denmark'.split()
goal = 'the prince am I'.split()

def all_stories_of_length(n, vocabulary):
    if n == 0:
        yield[]
    else:
        for story in all_stories_of_length(n-1, vocabulary):
            for word in vocabulary:
                yield story + [word]
            
count = 0          
for index, story in enumerate(all_stories_of_length(len(goal), vocabulary)):
    count += 1
    if count < 10:
        print(index, story)
    # if story == goal:
    #     print('Found it!')
    #     break
    
    