# Excalibur: Strike of Asgard

A 2D action-game developed in **C++ using modern OpenGL**, featuring Thor, Doctor Strange, and members of Hydra.

The project demonstrates character movement, combat mechanics, collision detection, health management, and animations using geometric transformations.

## Story

Thor is destined to become king and save his kingdom. However, to fulfill his destiny, he must first recover his hammer, Mjölnir, which was stolen from the castle when he was a child.

The hammer is hidden on an altar at Earthbound Lake, guarded by Hydra, the organization responsible for its disappearance. The location has long been forgotten, but legend tells of a magical spell capable of teleporting someone there.

Doctor Strange, the magician who raised Thor, discovers that the castle contains a secret library filled with powerful spells. Remembering a childhood story told by Thor's father, they follow its clues, discover the hidden library, and find the teleportation spell.

Doctor Strange opens a portal to Earthbound Lake, where the two travel through a forest toward the altar. As they approach, Hydra guards discover them.

Without his hammer, Thor cannot confront the enemies directly. Doctor Strange uses his magic to stun the guards, causing them to float temporarily while Thor attempts to summon Mjölnir.

The hammer responds to Thor's call, spinning through the air before landing in his hand. With his power restored, Thor and Doctor Strange defeat the Hydra guards and eventually eliminate the organization's threat.

Peace returns to the kingdom, and Thor fulfills his destiny by becoming king.

## Gameplay

The 2D project recreates the confrontation between Thor, Doctor Strange, and Hydra guards at Earthbound Lake.

The scene contains four characters: Thor, Doctor Strange, and two Hydra enemies, alongside an altar and Thor's hammer.

### Controls

| Key | Action |
|---|---|
| W | Move Thor upward |
| A | Move Thor left |
| S | Move Thor downward |
| D | Move Thor right |
| H | Summon Thor's hammer |
| J | Attack a nearby enemy with Thor |
| SPACE | Cast Doctor Strange's stunning spell |

### Thor's Abilities

**Hammer Summoning**

Pressing `H` summons Mjölnir. The hammer flies toward Thor while rotating around its center.

After reaching Thor's hand, it stops rotating and follows his movement.

**Hammer Attack**

Once Thor has collected his hammer, pressing `J` attacks a nearby living enemy.

Each successful attack deals **25 damage**. An enemy must be within attack range for the attack to succeed.

### Doctor Strange's Abilities

**Stunning Spell**

Pressing `SPACE` launches a magical projectile toward the enemies.

When a projectile collides with an enemy:

- The enemy receives 15 damage.
- The projectile disappears.
- The enemy is stunned for approximately 3 seconds.
- The enemy floats upward, increases slightly in size, and returns to its original position and size.

## Health and Combat

Each character starts with **100 health points**.

| Attack | Damage |
|---|---:|
| Thor's hammer | 25 HP |
| Doctor Strange's spell | 15 HP |

Health cannot fall below zero. When an enemy's health reaches 0, it disappears from the scene.

Successful attacks and remaining health are displayed in the console.

## Technical Features

### Complex Animations

**1. Thor's Hammer Animation**

The hammer combines translation and rotation. Its position changes over time as it moves toward Thor, while a rotation transformation makes it spin around the Z-axis.

After collection, its rotation resets and its position follows Thor's hand.

**2. Enemy Stun Animation**

When Doctor Strange's spell hits an enemy, a time-dependent animation combines vertical translation and scaling.

The enemy rises and grows slightly before returning to its normal appearance after approximately three seconds.

### Collision Detection

The game uses coordinate-based collision checks to determine when Doctor Strange's projectile hits an enemy.

Thor's attack also checks whether an enemy is within the permitted horizontal and vertical attack range.

### Damage Calculation

The damage system subtracts the attack's damage value from the target's current health.

Health is limited to a minimum of zero, and defeated enemies are excluded from rendering and further attacks.

### 2D Objects

Characters, the altar, the spell projectile, and Mjölnir are constructed from simple geometric primitives.

The scene uses OpenGL transformations to position, scale, and animate these objects.

## Technologies

- **C++** — Gameplay logic and character behavior
- **OpenGL** — 2D rendering
- **GLEW** — OpenGL extension loading
- **GLFW** — Window creation and keyboard input
- **GLM** — Vector and matrix calculations
- **GLSL** — Vertex and fragment shaders
- **Visual Studio 2022** — Development environment

The rendering implementation uses modern OpenGL techniques, including VAOs, VBOs, IBOs, and shaders.
