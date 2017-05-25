DefinitionBlock ("ACPITABL.dat", "SSDT", 1, "MSFT", "ECHO", 1)
{
    Scope (\_SB)
    {
        //
        // Define a device node that represents a touchpad
        //
        Device(TP02)
		{
			Name(_ADR, 0)
			Name(_HID, "AWTP0006") 
			Name(_UID, 0)
			Method (_STA, 0, NotSerialized)  
			{
				Return (0x0F)
			}
			Method(_CRS, 0x0, NotSerialized)
			{
			    Name (RBUF, ResourceTemplate ()
			    {
					//gt82x tp address is 0x5d
			        I2CSerialBus(0x5D, ControllerInitiated, 400000, AddressingMode7Bit, "\\_SB.I2C0", , )
			        GpioInt(Edge, ActiveLow, Exclusive, PullDefault, 0, "\\_SB.PIOH") {4}
			        GpioIo(Exclusive, PullDefault, 0, 25, IoRestrictionOutputOnly, "\\_SB.PIOH") {8}
			    })
			    Return(RBUF)
			}
		}//End of device 'TP02'
    }
}
