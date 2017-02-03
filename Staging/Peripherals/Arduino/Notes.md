`Packet.cpp` is *far* too complicated for what it needs to be.
Simply use a packet struct -- that's all we need.

```c++
const size_t DATA_BYTES = 8;
const size_t COMMAND_SIZE = sizeof(Command); // 4 bytes

struct Packet
{
    Command command; // 4 bytes for command
    // all we need though is a single byte, so maybe consider making Command
    // index a char array
    char data[DATA_BYTES]; // 8 bytes of data
};

const size_t PACKET_SIZE = sizeof(Packet); // should be 12 bytes as it stands. Maybe use #pragma pack (1)
```

Avoid overcomplicating things. There's no need for a class for something so simple.
We'll need a `PacketHandler` to interpret and construct `Packet`s, but adding the overhead of
building a `Packet` class that wraps a `packet` struct is bloated and unnecessary.

