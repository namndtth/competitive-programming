<p>Alice and Bob take turns playing a game, with <strong>Alice starting first</strong>.</p>

<p>There are <code>n</code> stones arranged in a row. On each player's turn, they can <strong>remove</strong> either the leftmost stone or the rightmost stone from the row and receive points equal to the <strong>sum</strong> of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.</p>

<p>Bob found that he will always lose this game (poor Bob, he always loses), so he decided to <strong>minimize the score's difference</strong>. Alice's goal is to <strong>maximize the difference</strong> in the score.</p>

<p>Given an array of integers <code>stones</code> where <code>stones[i]</code> represents the value of the <code>i<sup>th</sup></code> stone <strong>from the left</strong>, return <em>the <strong>difference</strong> in Alice and Bob's score if they both play <strong>optimally</strong>.</em></p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> stones = [5,3,1,4,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> stones = [7,90,5,1,100,10,10,2]
<strong>Output:</strong> 122</pre>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>n == stones.length</code></li> 
 <li><code>2 &lt;= n &lt;= 1000</code></li> 
 <li><code>1 &lt;= stones[i] &lt;= 1000</code></li> 
</ul>

<div><div>Related Topics</div><div><li>Array</li><li>Math</li><li>Dynamic Programming</li><li>Game Theory</li></div></div><br><div><li>👍 980</li><li>👎 167</li></div>