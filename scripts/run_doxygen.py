#!/usr/bin/env python3
"""
PlatformIO Extra Script for Smart Aquarium Guardian
Automatically generates Doxygen documentation during build
"""

import os
import subprocess
from pathlib import Path

def before_build(source, target, env):
    """
    Called before the build starts.
    Generates Doxygen documentation.
    """
    project_dir = env.get("PROJECT_DIR")
    doxyfile = os.path.join(project_dir, "Doxyfile")
    
    if not os.path.exists(doxyfile):
        print("[WARNING] Doxyfile not found at:", doxyfile)
        return
    
    print("\n" + "="*60)
    print("[Doxygen] Generating API documentation...")
    print("="*60)
    
    try:
        # Run doxygen
        result = subprocess.run(
            ["doxygen", doxyfile],
            cwd=project_dir,
            capture_output=True,
            text=True,
            timeout=120  # 2 minute timeout
        )
        
        # Check result
        if result.returncode == 0:
            print("[Doxygen] ✓ Documentation generated successfully!")
            html_dir = os.path.join(project_dir, "docs", "doxygen", "html")
            if os.path.exists(html_dir):
                index_file = os.path.join(html_dir, "index.html")
                print(f"[Doxygen] ✓ View docs: {html_dir}")
        else:
            print("[Doxygen] ✗ Generation had warnings or errors:")
            if result.stderr:
                print(result.stderr[:500])  # Print first 500 chars of error
    
    except FileNotFoundError:
        print("[WARNING] Doxygen not found. Install it to enable auto-generation.")
        print("          Windows: Download from https://www.doxygen.nl/download.html")
        print("          Or use: choco install doxygen")
    except subprocess.TimeoutExpired:
        print("[ERROR] Doxygen generation timed out (>120 seconds)")
    except Exception as e:
        print(f"[ERROR] Failed to generate documentation: {e}")
    
    print("="*60 + "\n")

# Register the pre-build hook
Import("env")
env.AddPreAction("$BUILD_DIR/${PROGNAME}.elf", before_build)
