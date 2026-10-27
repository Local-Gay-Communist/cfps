```markdown
# AGENTS.md

## Setup
- **Project**: C-based 3D FPS game named `cfps`
- **Compiler**: Use `gcc` with `-std=c11 -Wall -Wextra` flags
- **Dependencies**: Install SDL2, GLAD, and Lua (for scripting)
- **Build System**: Linux-focused CMake + Ninja
  - Configure with `cmake -S . -B build && cmake --build build`

## Commands
- **Build**: `ninja -C build` (or `cmake --build build`)
- **Run Game**: `build/game` (use `TF_ENV=dev` for debug rendering)
- **Run Editor**: `build/editor` (requires map files in `maps/` directory)
- **Test**: `build/test` (use `TEST_FOCUSED=true` for targeted runs)

## Scripting
- **Lua API**: 
  - High-level, human-readable extensions for game mechanics & AI
  - Scripts in `scripts/` directory
  - Use `script_api.h` for entity manipulation
  - Debug with `SCRIPT_DEBUG=1` environment variable

## Architecture
- **Modular**: 
  - `src/render/` - OpenGL rendering pipeline
  - `src/physics/` - Box2D integration
  - `src/ai/` - Enemy behavior trees
  - `src/editor/` - Map/level editing tools
- **Main Loop**: Defined in `src/main.c`

## Map File Design
- **Format**: Compiled binary with `CFPS_MAP` magic number
- **Structure**: 
  - 4-byte magic number `CFPS`
  - 4-byte version number
  - 4-byte entity count
  - Compressed entity data (LZ4)
- **Files**: Stored as `maps/*.map.bin`
- **Tools**: 
  - `map_exporter` (C tool for JSON→binary conversion)
  - `map_compiler` (C tool for binary validation/loading)

## Development Plan
### Phase 1: Foundation
1. Set up CMake project structure with `src/`, `maps/`, and `scripts/`
2. Implement core SDL2 window/graphics setup
3. Create basic entity system with memory arena allocation
4. Implement Lua scripting interface

### Phase 2: Core Systems
1. Develop OpenGL rendering pipeline (`src/render/`)
2. Implement Box2D physics integration (`src/physics/`)
3. Create enemy AI behavior trees (`src/ai/`)
4. Set up map loading system with binary format

### Phase 3: Editor Tools
1. Develop map editor with level design tools (`src/editor/`)
2. Implement map file exporter (`map_exporter`)
3. Create entity property editors and visualizers
4. Add versioning and compression support

### Phase 4: Polishing
1. Implement debug rendering and profiling tools
2. Add Lua API for AI and level scripting
3. Create test maps and enemy configurations
4. Optimize memory usage and performance

### Phase 5: Deployment
1. Implement CI/CD integration with GitHub Actions
2. Create release binaries for Linux
3. Document scripting API and map format
4. Prepare game launcher and packaging

## Gotchas
- **Memory**: Never use `malloc()` for entity data - use `arena_alloc()`
- **Scripting**: Don't modify `scripts/` during runtime
- **Build**: Clean with `cmake --build build --target clean`
- **Maps**: Use `map_exporter` to generate `.map.bin` files

```