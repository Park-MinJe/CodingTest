def solution(people, limit):
    number_of_boats = 0
    
    sorted_people = sorted(people)
    
    left = 0
    right = len(sorted_people)-1
    while left < right:
        if sorted_people[left]+sorted_people[right] <= limit:
            number_of_boats += 1
            left += 1
        right -= 1
    
    return len(sorted_people)-number_of_boats