Player = 
{
	name = "Player2",
	initial_position = { 300.0, 200.0, 0.0 },
	
	SpriteInfo = { 
			SpritePath = "data\\UFO.dds"
	},

	PhysicsInfo = 
	{
		mass = 10.0,
		coefficientOfDrag = 0.001
	},
	velocity = { 150.0, 0.0, 0.0 },
	Center = { 0.0, 32.0, 0.0 },
	BoxExtents = { 32.0, 32.0, 0.0 },
	Roation = 0,
	Controller = "PlayerController",
	Serializable = 1,
	Trigger = 2
}
