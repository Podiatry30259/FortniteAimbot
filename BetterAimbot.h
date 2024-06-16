namespace UnrealEngine {
	namespace Structs {
		struct FRotator5 { // ue5
			double Pitch;
			double Yaw;
			double Roll;
		};

		struct FRotator4 {
			float Pitch;
			float Yaw;
			float Roll;
		};

		struct FortniteOnly {
			char Pad0[0x1C5]; // Latest
			FRotator5 Rotation;
			char Pad1[0x6F]; // Remaining Bytes
		};

		struct ValorantOnly {
			char Pad0[0x20]; // Latest
			FRotator4 Pending_Verify_Rotation;
			char Pad1[0x9E]; // Latest
			FRotator4 Final_Rotation;
		};

		long long Finals = 0x50C; // Latest
	}

	namespace BetterAimbot {
		namespace Fortnite {
			void WriteAngles(long long TextAddress, Structs::FRotator5& Angles) {
				const long long FirstPointer = TextAddress + 0x82482DC;
				const long long WriteableAddress = FirstPointer + 3;

				auto RelativePointer = *(long*)(WriteableAddress);
				auto StructPointer = *(Structs::FortniteOnly**)(RelativePointer);

				StructPointer->Rotation = Angles;
			}

		} // Public Now

		namespace Valorant {
		} // Private

		namespace TheFinals {
		} // Private
	}
}
