#!/bin/ruby

require 'json'
require 'stringio'

class TreeNode
    attr_accessor :children

    def initialize
        # To find height of tree, value stored in nodes does not matter. 
        # So in input also we are not given this field. 
        # @val = 0
        @children = []
    end
end


# ------------------------------ START ----------------------------

# class TreeNode
#     attr_accessor :children

#     def initialize
#         # To find height of tree, value stored in nodes does not matter. 
#         # So in input also we are not given this field. 
#         # @val = 0
#         @children = []
#     end
# end


# Complete the find_height function below.
def find_height(root)
    # Handle base case when root is a leaf node.                    
    if root.children.length == 0              
        return 0
    end
    h = 0
    for i in 0...root.children.length
        temp = root.children[i]
        # Find height of each children and store the maximum height of children. 
        h = [h, find_height(temp)].max
    end
    return h + 1
end

# ------------------------------ STOP ----------------------------


$N = 0

def build_tree(from, to)
    $N = from.length + 1
    address = Hash.new
    for i in 1..$N
        address[i] = TreeNode.new
    end
    for i in 0...$N - 1
        address[from[i]].children.push(address[to[i]])
    end
    return address[1]
end


fptr = $stdout.dup

k = gets.strip.to_i

from_count = gets.strip.to_i

from = Array.new(from_count)

from_count.times do |i|
    from_item = gets.strip.to_i
    from[i] = from_item
end

to_count = gets.strip.to_i

to = Array.new(to_count)

to_count.times do |i|
    to_item = gets.strip.to_i
    to[i] = to_item
end

root = build_tree from, to
res = find_height(root)

fptr.write res
fptr.write "\n"

fptr.close()

