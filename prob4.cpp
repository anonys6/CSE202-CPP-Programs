#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int rows, cols;
vector<vector<int>> grid;
vector<vector<int>> blockGrid;
unordered_map<int, vector<pair<int, int>>> blockCells;
set<int> activeBlocks;
int targetBlockId;

void assignBlocks() {
    int blockId = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                int color = grid[i][j];
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                blockGrid[i][j] = blockId;
                blockCells[blockId].push_back({i, j});
                if (color == targetBlockId) {
                    targetBlockId = blockId;
                }
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && grid[nx][ny] == color) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            blockGrid[nx][ny] = blockId;
                            blockCells[blockId].push_back({nx, ny});
                        }
                    }
                }
                activeBlocks.insert(blockId);
                ++blockId;
            }
        }
    }
}

bool isTargetBlockAccessible() {
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; ++i) {
        if (blockGrid[i][cols - 1] == -1) {
            q.push({i, cols - 1});
            visited[i][cols - 1] = true;
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]) {
                if (blockGrid[nx][ny] == -1) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else {
                    int bId = blockGrid[nx][ny];
                    if (bId == targetBlockId) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

set<int> getObstructingBlocks() {
    set<int> obstructingBlocks;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; ++i) {
        if (blockGrid[i][cols - 1] == -1) {
            q.push({i, cols - 1});
            visited[i][cols - 1] = true;
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if (blockGrid[nx][ny] == -1) {
                    q.push({nx, ny});
                } else {
                    int bId = blockGrid[nx][ny];
                    if (bId != targetBlockId) {
                        obstructingBlocks.insert(bId);
                    }
                }
            }
        }
    }
    return obstructingBlocks;
}

void removeBlock(int bId) {
    activeBlocks.erase(bId);
    for (auto &cell : blockCells[bId]) {
        int x = cell.first;
        int y = cell.second;
        blockGrid[x][y] = -1;
    }
}

void applyGravity(set<int> &removedBlocks) {
    bool changed;
    do {
        changed = false;
        set<int> toRemove;
        for (int bId : activeBlocks) {
            bool supported = false;
            for (auto &cell : blockCells[bId]) {
                int x = cell.first;
                int y = cell.second;
                if (x + 1 < rows && blockGrid[x + 1][y] != -1) {
                    supported = true;
                    break;
                }
            }
            if (!supported) {
                toRemove.insert(bId);
            }
        }
        if (!toRemove.empty()) {
            changed = true;
            for (int bId : toRemove) {
                removeBlock(bId);
                removedBlocks.insert(bId);
            }
        }
    } while (changed);
}

int main() {
    cin >> rows >> cols;
    grid.resize(rows, vector<int>(cols));
    blockGrid.resize(rows, vector<int>(cols, -1));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
    int targetColor;
    cin >> targetColor;

    targetBlockId = targetColor;

    assignBlocks();

    int totalBlocksRemoved = 0;
    while (true) {
        if (isTargetBlockAccessible()) {
            break;
        }
        set<int> obstructingBlocks = getObstructingBlocks();
        if (obstructingBlocks.empty()) {
            break;
        }
        
        int blockToRemove = *obstructingBlocks.begin();
        removeBlock(blockToRemove);
        ++totalBlocksRemoved;
        set<int> blocksRemovedDueToGravity;
        applyGravity(blocksRemovedDueToGravity);
        totalBlocksRemoved += blocksRemovedDueToGravity.size();
    }

    cout << totalBlocksRemoved << endl;

    return 0;
}